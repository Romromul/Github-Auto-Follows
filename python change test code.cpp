
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "cpp-httplib-master/httplib.h"
#include "nlohmann/json.hpp"

using namespace std;

struct Arguments {
    string token;
    string myUsername;
    string userTarget;
    string file;
    string maxFollowers;
};

httplib::Headers getHeaders(const Arguments &args) {
    string authString = args.myUsername + ":" + args.token;
    string encodedAuth = httplib::detail::base64_encode(authString);
    return {{"Authorization", "Basic " + encodedAuth}};
}

void authenticate(const Arguments &args) {
    httplib::Client client("https://api.github.com");
    auto res = client.Get("/user", getHeaders(args));

    if (res && res->status == 200) {
        cout << "Authentication Succeeded!" << endl;
    } else {
        cerr << "Failure to Authenticate, please check Personal Access Token and Username!" << endl;
        exit(1);
    }
}

vector<string> getFollowers(const Arguments &args, httplib::Client &client) {
    vector<string> usersToFollow;

    auto res = client.Get(("/users/" + args.userTarget + "/followers").c_str(), getHeaders(args));
    if (res && res->status == 200) {
        auto links = httplib::detail::parse_header(res->get_header_value("Link").c_str());
        string lastPage = links.rbegin()->second;
        cout << "Grabbing People to Follow\nThis may take a while... there are " << lastPage << " pages to go through." << endl;

        for (int page = 1; page <= stoi(lastPage); ++page) {
            res = client.Get(("/users/" + args.userTarget + "/followers?limit=100&page=" + to_string(page)).c_str());
            if (res && res->status == 200) {
                auto json = nlohmann::json::parse(res->body);
                for (const auto &user : json) {
                    usersToFollow.push_back(user["login"]);
                }
                if (!args.maxFollowers.empty() && usersToFollow.size() >= stoi(args.maxFollowers)) {
                    break;
                }
            }
        }
    }

    return usersToFollow;
}

void saveToFile(const string &filename, const vector<string> &data) {
    ofstream file(filename);
    if (file.is_open()) {
        nlohmann::json jsonArr(data);
        file << setw(4) << jsonArr << endl;
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
        exit(1);
    }
}

void followUsers(const Arguments &args, const vector<string> &usersToFollow, httplib::Client &client) {
    cout << "Starting to Follow Users... This WILL Take a while, we must avoid being rate-limited!" << endl;

    for (const auto &user : usersToFollow) {
        while (true) {
            this_thread::sleep_for(chrono::seconds(2));
            auto res = client.Put(("/user/following/" + user).c_str(), getHeaders(args), nullptr);

            if (res && res->status == 204) {
                break;
            } else {
                cout << res->status << endl;
                cerr << "We may have been rate-limited, waiting until it stops!" << endl;
                this_thread::sleep_for(chrono::seconds(10));
            }
        }
    }
}

int main() {
    Arguments args;
    args.token = "YOUR_GITHUB_TOKEN";  // Replace with your GitHub token
    args.myUsername = "YOUR_GITHUB_USERNAME";  // Replace with your GitHub username
    args.userTarget = "TARGET_USER";  // Replace with the target GitHub user
    args.file = "";
    args.maxFollowers = "";

    authenticate(args);

    httplib::Client client("https://api.github.com");

    vector<string> usersToFollow;

    if (args.file.empty()) {
        usersToFollow = getFollowers(args, client);
        string filename = chrono::system_clock::now().time_since_epoch().count() + "_FOLLOWED.json";
        saveToFile(filename, usersToFollow);
    } else {
        // Add code to read from file if necessary
    }

    followUsers(args, usersToFollow, client);

    return 0;
}
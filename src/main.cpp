#include <iostream>
#include <map>
#include "HTTPRequest.hpp"
#include "dotenv.h"

// Import OHLC data from AlphaVantage API key
// std::map<std::string, double> requestData() {

void requestData() {
    auto& env = dotenv::env.load_dotenv();
    std::string alpha_vantage_api_key = env["ALPHA_VANTAGE_API_KEY"]

    try {
        http::Request request{"https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" << "NVDA" << "&apikey=" << alpha_vantage_api_key};
        const auto response = request.send("GET");

        std::cout << std::string{response.body.begin(), response.body.end() << "\n"}

    } catch (const std::exception& e) {
        std:cerr << "Request failed, error: " << e.what() << "\n";
    }

}

int main() {
    requestData()

    return 0;
}

// Format OHLC data

// Backtest SMA indicator using OHLC data
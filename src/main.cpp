#include <zmq.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    zmq::context_t context(1);
    zmq::socket_t publisher(context, zmq::socket_type::pub);

    publisher.bind("tcp://*:5556");

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Give PlotJuggler time to connect

    for (int i = 0; i < 1000; ++i) {
        float value = static_cast<float>(i * 0.1f);

        // Create a JSON object with a key-value pair
        json j;
        j["altitude"] = value;

        std::string payload = j.dump(); // Convert JSON to string

        zmq::message_t message(payload.begin(), payload.end());
        publisher.send(message, zmq::send_flags::none);
        std::cout << "Sent: " << payload << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

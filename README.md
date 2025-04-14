## ZeroMQ JSON Publisher for PlotJuggler

This is a minimal example demonstrating how to stream real-time JSON data using ZeroMQ and visualize it in [PlotJuggler](https://github.com/facontidavide/PlotJuggler).

The example publishes simulated `altitude` data over a `PUB` socket, and PlotJuggler receives it using its **ZeroMQ plugin with `json` protocol**.

---

### Requirements

#### Dependencies

| Library               | Notes                                            |
|------------------------|--------------------------------------------------|
| [ZeroMQ](https://zeromq.org/)         | Used for PUB/SUB communication |
| [nlohmann/json](https://github.com/nlohmann/json) | Header-only JSON library      |
| [PlotJuggler](https://github.com/facontidavide/PlotJuggler) | GUI for real-time plotting (install separately) |

#### Installation

##### 1. Install dependencies via [vcpkg](https://github.com/microsoft/vcpkg)

```bash
git clone https://github.com/microsoft/vcpkg
cd vcpkg
./bootstrap-vcpkg.sh # or bootstrap-vcpkg.bat on Windows
./vcpkg install cppzmq nlohmann-json
```

##### 2. Build the project

```bash
git clone https://github.com/yourusername/zmq_plotjuggler_example.git
cd zmq_plotjuggler_example
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
make
```

> Replace `/path/to/vcpkg` with your actual vcpkg path.

---

### 🚀 Running the Example

1. **Launch PlotJuggler**
   - Open PlotJuggler
   - Go to `Streaming > ZeroMQ Subscriber`
   - Set:
     - `Address`: `tcp://127.0.0.1:5556`
     - `Socket Type`: `SUB`
     - `Connect/Bind`: `Connect`
     - `Protocol`: `json`
     - `Topics`: *(leave empty)*
   - Click **Connect**
   - Keep PlotJuggler open

2. **Run the publisher**

```bash
./zmq_json_publisher
```

You should see a real-time signal `/altitude` appear in PlotJuggler.

---

PlotJuggler:
- A live graph of `altitude` increasing over time

---

### 🛠 Troubleshooting

- **PlotJuggler crashes or shows nothing** → Make sure:
  - You selected `json` as protocol (not `data_tamer`)
  - You clicked **Connect before running the publisher**
  - Your JSON is valid (`{"altitude": 12.3}` not `altitude: 12.3`)
- **Still nothing?** Add `std::this_thread::sleep_for(std::chrono::seconds(3));` at the beginning of `main()` to give PlotJuggler time to connect

---

### ✨ Want to send more variables?

Just expand the JSON object:
```cpp
json j;
j["altitude"] = value;
j["velocity"] = velocity;
j["throttle"] = throttle;
```

---

Let me know if you'd like a `CMakeLists.txt` as well or a pre-packaged `.zip` project folder!

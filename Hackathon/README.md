# 🚨 ROS - Rescue Operating System

A disaster zone resource management and rescue operation simulator developed by Team SegFault for our Semester 3 DSA hackathon.

## 📋 Overview

ROS (Rescue Operating System) is a command-line application designed to efficiently manage resources and coordinate rescue operations across multiple disaster zones. It implements a priority-based resource allocation system and ensures optimal rescue operations based on available resources.

### 🌟 Key Features

- Dynamic disaster zone management with priority levels
- Intelligent resource allocation algorithm
- Priority-based rescue operations
- Real-time resource reallocation for zones with zero resources
- Comprehensive tracking of rescued individuals
- Resource optimization across multiple zones

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make (optional, for build automation)
- Standard C libraries

## 💻 Usage

ROS offers an interactive command-line interface with the following options:

- `Z` - Add a new disaster zone
- `A` - Allocate resources to zones
- `P` - Rescue people
- `D` - Display current status
- `Q` - Quit program

### Adding a Zone
When adding a new zone, you'll need to provide:
- Zone number (unique identifier)
- Priority level (1-5, where 1 is highest priority)
- Population count
- Names of people in the zone

### Resource Allocation
Resources are distributed based on zone priorities, with an intelligent reallocation system that ensures no zone with people remains without resources.

## 🏗 Architecture

The system is built using three main components:

- `main.c` - Program entry point and user interface
- `hack.c` - Core functionality implementation
- `hack.h` - Data structures and function declarations

### Data Structures

```c
ZONE - Manages disaster zone information
PERSON - Stores individual person data
RESCUED - Tracks rescued individuals
```

## 👥 Team SegFault

- Paranshu
- Vivian
- Prateek
- Noel

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎯 Future Improvements

- Graphical user interface
- Statistical analysis of rescue operations
- Multiple resource types support
- Real-time visualization of rescue operations
- Export/import functionality for zone data

---

Made with ❤️ by Team SegFault

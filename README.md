# LightCast

**Illuminate Possibilities, Transform Light into Innovation**

[![Built with](https://img.shields.io/badge/Built%20with-Markdown%20·%20C++-blue?style=flat&logo=c%2B%2B)](https://isocpp.org/)
[![License](https://img.shields.io/github/license/Ojash-Adhikari/LightCast)](https://github.com/Ojash-Adhikari/LightCast/blob/main/LICENSE)

<p align="center">
  <img src="https://github.com/Ojash-Adhikari/LightCast/assets/glass.png" alt="LightCast Demo" width="800"/>
  <img src="https://github.com/Ojash-Adhikari/LightCast/assets/object.png" alt="LightCast Demo" width="800"/>
</p>

## Table of Contents
- [Overview](#overview)
- [Why LightCast?](#why-lightcast)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Overview

**LightCast** is an advanced developer toolkit designed for creating **interactive optical simulations and visualizations**.  
It enables precise modeling of light behavior — including **refraction**, **reflection**, and **transparent material interactions** — in dynamic, real-time scenes.

Perfect for developers, researchers, and educators building physics engines, educational tools, or visually stunning ray-tracing demos.

## Why LightCast?

LightCast empowers you to create **realistic optical visualizations** with ease and precision.

### ✨ Features

| Feature                  | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| 🔬 **Scientific Accuracy**   | Implements Snell’s Law, ray tracing, and precise angle calculations         |
| 🎨 **Interactive Control**   | Real-time scene manipulation via keyboard/mouse input                      |
| 🚀 **Modular Architecture**  | Core components (`MoveBox`, `LightSource`, `Glass`) for easy customization |
| 💡 **High Visual Fidelity**  | Accurate rendering of transparent materials and complex light paths        |
| ⚙️ **Developer-Friendly**    | Seamless integration with custom graphics engines and simulation tools     |

## Getting Started

### Prerequisites

Make sure you have the following installed:

- **C++ Compiler** (GCC, Clang, or MSVC) with C++17+ support
- **CMake** ≥ 3.14
- **Make** (or another compatible build system)

### Installation

```bash
git clone https://github.com/Ojash-Adhikari/LightCast.git
cd LightCast
cmake -S . -B build
cmake --build build
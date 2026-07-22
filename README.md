# WE ARE BULIDING A RADAR USING THE CPP AND RAYLIB
# g++ main.cpp -IC:\raylib\include -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -o main
"command to complie"
EEYE/
│
├── frontend/                  # Web Dashboard (React)
│   ├── public/
│   ├── src/
│   │   ├── components/
│   │   ├── pages/
│   │   ├── hooks/
│   │   ├── services/
│   │   ├── context/
│   │   ├── assets/
│   │   └── App.jsx
│   └── package.json
│
├── backend/                   # API Server
│   ├── app/
│   │   ├── api/
│   │   ├── models/
│   │   ├── services/
│   │   ├── database/
│   │   ├── radar/
│   │   ├── simulation/
│   │   ├── utils/
│   │   └── main.py
│   ├── requirements.txt
│   └── .env
│
├── radar-engine/              # Raylib Simulation
│   ├── include/
│   ├── src/
│   ├── assets/
│   ├── build/
│   └── CMakeLists.txt
│
├── ai-engine/                 # Future AI Modules
│   ├── object_detection/
│   ├── tracking/
│   ├── classification/
│   └── prediction/
│
├── database/
│   ├── schema.sql
│   └── migrations/
│
├── docs/
│   ├── diagrams/
│   ├── screenshots/
│   ├── architecture.md
│   ├── api.md
│   └── presentation/
│
├── tests/
│
│
└── LICENSE
Project Overview

EEYE (Electronic Eye) is a software-defined air surveillance radar platform that simulates the operation of a modern radar command center. The system combines a real-time radar visualization engine, a web-based monitoring dashboard, backend APIs, and future AI modules for target tracking and classification.

The objective is to demonstrate radar concepts, software architecture, and modern full-stack development without requiring specialized radar hardware.

System Architecture
                     User
                      │
                      ▼
        ┌────────────────────────┐
        │   React Frontend       │
        │  Command Dashboard     │
        └──────────┬─────────────┘
                   │ REST API
                   ▼
        ┌────────────────────────┐
        │     Backend Server     │
        │ Authentication         │
        │ Radar Data API         │
        │ Target Management      │
        │ Alert System           │
        └──────────┬─────────────┘
                   │
        ┌──────────┴─────────────┐
        │                        │
        ▼                        ▼
  Radar Engine              Database
 (Raylib C++)          PostgreSQL/MySQL
        │
        ▼
 AI Detection Engine (Future)
Technology Stack
Layer	Technology
Frontend	React, Vite, Tailwind CSS
Backend	Python, FastAPI
Radar Engine	C++, Raylib
Database	PostgreSQL
AI Module	Python, OpenCV, YOLO (Future)
Authentication	JWT
API	REST
Version Control	Git & GitHub
Frontend Responsibilities
Live radar dashboard
System status
Target list
Alert notifications
Statistics
Mission history
User login
Responsive interface
Dark military theme
Backend Responsibilities
User authentication
Radar data processing
Target management
Alert generation
Logging
REST API
Communication with AI module
Database operations
Radar Engine Responsibilities
Radar sweep animation
Grid rendering
Range rings
Blinking targets
Moving targets
Sweep glow
Collision detection
Coordinate conversion
Zoom and scaling
AI Module (Future)
Aircraft detection
Threat classification
Object tracking
Route prediction
Target prioritization
Automatic alert generation
Database

Suggested tables:

Users
Targets
RadarEvents
Alerts
Missions
SystemLogs
Settings
Features
Current
Modern radar interface
Rotating sweep
Radar rings
Grid system
Information panels
Modular C++ architecture
Upcoming
Sweep glow
Target movement
Blinking targets
Zoom control
Multiple radar modes
Animated HUD
CRT effect
Web dashboard
AI detection
Replay mode
Export reports
API Endpoints (Planned)
GET    /targets
POST   /targets
PUT    /targets/{id}
DELETE /targets/{id}

GET    /alerts
GET    /status
GET    /system

POST   /login
POST   /logout
POST   /refresh
Database Flow
Radar Engine
      │
      ▼
Backend API
      │
      ▼
Database
      │
      ▼
Frontend Dashboard
Development Roadmap
Phase 1
Radar Engine (Raylib)
Phase 2
Moving Targets
Phase 3
Backend API
Phase 4
Database Integration
Phase 5
React Dashboard
Phase 6
AI Integration
Phase 7
Deployment
Future Scope
3D radar visualization
Drone monitoring
Weather radar mode
Satellite tracking
Multi-radar synchronization
Mobile application
Cloud deployment
Machine learning for threat prediction
Voice alerts
Real-time networking


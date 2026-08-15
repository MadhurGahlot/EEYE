from fastapi import FastAPI
from pydantic import BaseModel 


from app.routes.radar import radar_router


eeye = FastAPI(
    title = "EEYE BACKEND SERVICE ",
    description= "This is the backend ",
    contact = {
        "name" : "DEVELOPER",
        "email" : "236301126@gkv.ac.in"
    },
)


eeye.include_router(radar_router)

@eeye.get("/")
def out():
    return {"title": "THIS IS THE BACKEND FOR THE PROJECT CALLED EEYE",
            "Status" : "OK",
            "Date" : "11-08-2026 "}

@eeye.get("/developers")
def developers():
    return {
          "title" : "DEVELOPERS DETAILS",
          "name" : "236301126@gkv.ac.in",
          "role" : "BackendEngineer",
          "name " :"236301140@gkv.ac.in",
          "role" : " frontend "
    }

@eeye.get("/health")
def health():
    return {
        "status": "healthy",
        "service": "Sentinel Radar Backend",
        "version": "1.0.0"
    }
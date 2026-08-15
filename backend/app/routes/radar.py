from fastapi import APIRouter
from app.schemas import RadarStatus


radar_router = APIRouter(
    prefix= "/radar",
    tags=["Radar"]
)


radar = RadarStatus(
    enabled=True,
    scanning=True,
    status="ACTIVE",
    range_km=50)

@radar_router.get("/status")
def get_radar_status():
    return radar



@radar_router.post("/power")
def toggle_power():

    radar.enabled = not radar.enabled

    if radar.enabled:
        radar.status = "ACTIVE"
    else:
        radar.status = "OFFLINE"
        radar.scanning = False

    return radar

@radar_router.post("/scan")
def toggle_scanning():

    if not radar.enabled:
        return {
            "message": "Radar is OFFLINE",
            "radar": radar
        }

    radar.scanning = not radar.scanning

    if radar.scanning:
        radar.status = "ACTIVE"
    else:
        radar.status = "STANDBY"

    return radar
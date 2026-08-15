from pydantic import BaseModel

class user(BaseModel):
    username: str
    password: str
    email :  str


class RadarStatus(BaseModel):
    enabled: bool
    scanning: bool
    status: str
    range_km: float
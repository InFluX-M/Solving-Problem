import vehicle


class FlyingVehicle(vehicle.Vehicle):
    def __init__(self, fuel, number_of_fins, **kwargs):
        super().__init__(**kwargs)
        self.fuel = fuel
        self.number_of_fins = number_of_fins

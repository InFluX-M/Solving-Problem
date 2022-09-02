from work_place import WorkPlace, Consts
import math


class Mine(WorkPlace):
    def __init__(self, name):
        super().__init__(name)
        self.expertise = "mine"

    def calc_capacity(self):
        self.capacity = int(math.pow(self.level, 2))

    def calc_costs(self):
        return int(Consts.BASE_PLACE_COST+Consts.LEVEL_MUL*self.level)

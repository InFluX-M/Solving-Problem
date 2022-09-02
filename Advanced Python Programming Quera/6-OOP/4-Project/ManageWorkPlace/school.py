from work_place import WorkPlace, Consts
import math


class School(WorkPlace):
    def __init__(self, name):
        super().__init__(name)
        self.expertise = "school"

    def calc_capacity(self):
        self.capacity = int(math.floor(math.sqrt(self.level)))

    def calc_costs(self):
        return int(Consts.BASE_PLACE_COST * math.sqrt(math.floor(self.level)))

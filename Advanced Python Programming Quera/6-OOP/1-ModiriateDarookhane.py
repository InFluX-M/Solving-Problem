class Drug:
    def __init__(self, name, amount, price):
        self.name = name
        self.amount = amount
        self.price = price


class Pharmacy:
    def __init__(self, name):
        self.name = name
        self.drugs = []
        self.employees = []

    def add_drug(self, drug):
        self.drugs.append(drug)

    def add_employee(self, first_name, last_name, age):
        self.employees.append({"first_name": first_name, "last_name": last_name, "age": age})

    def total_value(self):
        total = 0.0
        for drug in self.drugs:
            total += (drug.amount * drug.price)
        return total

    def employees_summary(self):
        summary = "Employees:\n"

        i = 1
        for employee in self.employees:
            summary += f"The employee number {i} is {employee['first_name']} {employee['last_name']} who is {employee['age']} years old.\n"
            i += 1
        return summary

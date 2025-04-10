class Dot3D:
    def __init__(self, x, y, z, label=None):
        self.x = x
        self.y = y
        self.z = z
        self.label = label

    def distance_to(self, other):
        distance = ((self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2) ** 0.5
        return distance

    def add_vector(self, other):
        x = self.x + other.x
        y = self.y + other.y
        z = self.z + other.z
        label = self.label + "+" + other.label
        return Dot3D(x, y, z, label)

class Triangle3D:
    def __init__(self, dot1, dot2, dot3):
        self.dot1 = dot1
        self.dot2 = dot2
        self.dot3 = dot3
        self.edge1 = dot1.distance_to(dot2)
        self.edge2 = dot2.distance_to(dot3)
        self.edge3 = dot3.distance_to(dot1)

    def calculate_perimeter(self):
        return (self.edge1 + self.edge2 + self.edge3)     

    def calculate_area(self):
        s = (self.edge1 + self.edge2 + self.edge3) / 2
        return (s * (s - self.edge1) * (s - self.edge2) * (s -self.edge3)) ** 0.5

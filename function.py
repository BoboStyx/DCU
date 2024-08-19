
def read_students(file_name):
    with file_name open as f:
        students = f.readlines()
        Database =  XRUniv()
        for line in students:
            line = line.split()
            student = Student(line[0], line[1], line[2], line[3], line[4], line[5], line[6])
            Database.studs.append(student)

def phone():
    dict_number = {}
    while 1:
        line = input().split()
        operation = line[0]
        if operation == "add":
            name = line[1]
            number = int(line[2])
            dict_number[name] = number
        elif operation == "remove":
            name = line[1]
            if name in dict_number:
                dict_number.pop(name)
        elif operation == "edit":
            name = line[1]
            number = int(line[2])
            if name in dict_number:
                dict_number[name] = number
        elif operation == "quit":
            return
        print(dict_number)


phone()

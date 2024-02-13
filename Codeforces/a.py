def countNumbersLessThan(data:list , array_of_data:list):
    counter = list()
    for i in data:
        counter[i] = 0
        for j in array_of_data:
            if j < i:
                counter[i] += 1

    return list(counter.values())


if __name__ == "__main__":
    info = list(map(int, input().split()))
    array_of_data = list(map(int, input().split()))
    data = [int(input()) for _ in range(0, info[1])]  # my list of numbers
    result = countNumbersLessThan(data, array_of_data)
    for i in result:
        print(i)
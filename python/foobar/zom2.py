def are_overlapped(list1, list2):
    if list1[1] > list2[0]:
        return True
    return list


def merge(list1, list2):
    list = []
    if are_overlapped(list1, list2):
        list = [min(list2[0],list1[0]), max(list2[1], list1[1])]
    return list


def condense(list):
    list = sorted(list)
    x = 0
    y = 0
    final_list = [list[0]]
    while y < len(list)-1:
        if are_overlapped(final_list[x], list[y+1]) == True:
            final_list[x] = merge(final_list[x], list[y+1])
        else:
            x += 1
            final_list.append(list[y+1])
        y += 1
    return final_list 
    
def answer(interval):
    print interval
    list = condense(interval)
    print list
    total_time = 0
    for x in list:
        time = x[1] - x[0]
        total_time += time
    return total_time

print answer([[1,3]])
print answer([[10, 14],[4,18],[19,20],[19,20],[13,20]])
print answer([[1, 5],[11,14],[13,20],[6,9],[10,13],[3,7]])
print answer([[1,3],[3,6]])

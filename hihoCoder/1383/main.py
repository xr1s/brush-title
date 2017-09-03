def categorize(description, category):
    if len(description) != 1:
        if '0' + description[0] not in category:
            category['0' + description[0]] = { }
        categorize(description[1:], category['0' + description[0]])
    else: category['1' + description[0]] = None


def output(category, spaces):
    if not category: return
    for name, subcategory in sorted(category.items()):
        print spaces + name[1:]
        output(subcategory, spaces + '    ')


case = 0

while True:
    try: string = raw_input()
    except EOFError: exit()
    category = { }
    while string != '0':
        description = string.split('/')
        categorize(description, category)
        string = raw_input()
    case += 1
    print 'Case ' + str(case) + ':'
    output(category, '')

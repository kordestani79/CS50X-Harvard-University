from cs50 import get_int

while True:

    # input number
    height = get_int("Height: ")
    if (height > 0 and height < 9):
        for i in range(height):

            # print hashtag
            print(" " * (height - i - 1) + "#" * (i + 1))
        break

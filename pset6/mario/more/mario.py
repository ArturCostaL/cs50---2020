from  cs50 import get_int


def main():
    while True:
        h = get_int("Height: ")
        if h > 0 and h <= 8 :
            break;
    print_mario(h, h)

def print_mario(n, h):
    if n > 0:
        print_mario(n-1, h)
        print(f"{' ' * (h-n)}{'#' * n}  {'#' * n}")
main()
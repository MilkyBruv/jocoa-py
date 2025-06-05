import sys
import requests as rq
from bs4 import BeautifulSoup as BS

url = "https://repo1.maven.org/maven2/"

def get_soup(url) -> BS:
    soup = BS(rq.get(url).content, "html.parser")
    return soup


def main(args: list) -> None:
    soup = get_soup(url)

    while True:
        search = input("To search: ")
        results = []
        for i, a in enumerate(soup.find_all("a")):
            link = a.get_text()
            if (search in link) and ("/" in link):
                results.append(link)

        max_len = 8
        current_len = 0
        col = 0
        for i in range(2):
            for j, result in enumerate(results):
                if i == 0:
                    if len(result) >= max_len:
                        current_len = max_len
                        results[j] = result[0:max_len - 4] + ".../"
                    if len(result) > current_len:
                        current_len = len(result)
                if i == 1:
                    spaces = (current_len - len(result)) * " "
                    print(result + spaces + "\t", end="")
                    col += 1
                    if col == 5:
                        col = 0
                        print()
            print()

if __name__ == "__main__":
    main(sys.argv)



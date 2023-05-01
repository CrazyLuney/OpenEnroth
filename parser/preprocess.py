import sys
import os
import re

def remove_eof_enum(text):
    text = re.sub(r"^\s+EOF\s+=\s+\d+.+?\n", "", text, flags=re.RegexFlag.MULTILINE)
    return text

def remove_non_terminals_and_kinds(text):
    text = re.sub(r"^\s+\w+\s+=\s+\d+.+?\$\$0\n", "", text, flags=re.RegexFlag.MULTILINE)
    text = re.sub(r"\s+\$\$\d+(?=\n)", "", text, flags=re.RegexFlag.MULTILINE)
    return text

def main():
    if len(sys.argv) < 2:
        print("Invalid arguments")
        return
    
    in_file_path = sys.argv[1]

    if not os.path.isfile(in_file_path):
        print(in_file_path, "is not a file")
        return
    
    (basename, ext) = os.path.splitext(in_file_path)
    
    with open(in_file_path, "r") as f:
        text = f.read()

    if ext == '.h' or ext == '.hpp':
        new_text = remove_non_terminals_and_kinds(remove_eof_enum(text))
        changed = text != new_text
        text = new_text

    if changed:
        with open(in_file_path, "w") as f:
            f.write(text)
            print("Processed", in_file_path)

if __name__ == '__main__':
    main()
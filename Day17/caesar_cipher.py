def caesar_cipher(text, shift):
    total = 0
    for c in text:
        total += ord(c)
        print(total)
        if total >= ord('A') and total <= ord('Z'):
            total -= shift
        else:
            total += shift
        c = chr(total)
    return ''.join([c for c in text])

def caesar_cipher2(text, shift):
    ans = ""
    for i in range(len(text)):
        ch = text[i]

        if ch.isalpha():
            if (ch.isupper()):
                ans += chr((ord(ch) + shift-65) % 26 + 65)
            else:
                ans += chr((ord(ch) + shift-97)% 26 + 97)
        else:
            ans += ch

    return ans

outputtext = ""

with open('day17.txt', "r") as f:
    lines = f.readlines()
    for line in lines:
        cipher_text = caesar_cipher2(line, -7)
        outputtext += cipher_text

    


with open("day17_ino.txt", "w") as f:
    f.write(outputtext)

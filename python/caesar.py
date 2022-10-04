"""
Language : Python
Author : Ayesh Biswal
Github : https://github.com/heyyayesh


cypher(s: str, key: integer) -> str

This function takes a string and a key as input and encrypts the string
using the key.
"""


def cypher(s, key):
    encrypted = ''
    for i in s:
        if i.isalpha():
            newChar = chr((((ord(i.lower())-97) + key) % 26) + 97)
        else:
            newChar = i
        encrypted += newChar.upper() if i.isupper() else newChar
    return encrypted


"""
decypher(s: str, password: integer) -> str

This function takes a string and a password as input and decrypts the string
using the password.
"""


def decypher(s, password):
    decrypted = ''
    for i in s:
        if i.isalpha():
            newChar = chr((((ord(i.lower())-97) - password) % 26) + 97)
        else:
            newChar = i
        decrypted += newChar.upper() if i.isupper() else newChar
    return decrypted


if __name__ == '__main__':
    print('Enter a message to encrypt with an integer key')
    print(cypher(input('Message: '), int(input('Key: '))))

    print('Enter the recieved message along with the correct password to decrypt')
    print(decypher(input('Message: '), int(input('Password: '))))

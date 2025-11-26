import math

def columnar_encrypt(plaintext, key):
    # Remove spaces and convert to uppercase
    plaintext = plaintext.replace(" ", "").upper()
    key = key.upper()
    
    # Create numerical key order
    key_order = sorted([(char, i) for i, char in enumerate(key)])
    numeric_key = [0] * len(key)
    for i, (_, original_pos) in enumerate(key_order):
        numeric_key[original_pos] = i + 1

    # Create the matrix
    cols = len(key)
    rows = math.ceil(len(plaintext) / cols)
    padded_len = rows * cols
    plaintext += 'X' * (padded_len - len(plaintext))  # Padding

    matrix = [list(plaintext[i:i+cols]) for i in range(0, len(plaintext), cols)]

    # Read columns in order
    ciphertext = ''
    for num in range(1, cols + 1):
        col_idx = numeric_key.index(num)
        for row in matrix:
            ciphertext += row[col_idx]
    
    return ciphertext

# === MAIN ===
if __name__ == "__main__":
    key = input("Enter the key: ")
    plaintext = input("Enter the plaintext: ")
    
    encrypted_text = columnar_encrypt(plaintext, key)
    print("Encrypted Ciphertext:", encrypted_text)

import math

# Calculate the exact number of bits for a 1000-digit number
number_of_bits = math.ceil(1000 * math.log10(2))
print(number_of_bits)
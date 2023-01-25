# constants
ARRAY_SIZE = 10

# initialising the array with a label
# so an abstracted address to some allocated section in memory
# and values can be read using this direct label/address/pointer
.data
    array: .space ARRAY_SIZE
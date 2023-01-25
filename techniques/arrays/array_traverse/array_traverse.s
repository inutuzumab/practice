# print the values of an array while looping through it
.data
array: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10                      # each .word is 2 bytes

.text
main:
iterate_through_array:
		begin					                                # push the stack
        push $ra				                                # save the return address
		li $t0, 0				                                # store a counter

iterate_through_array__for_loop:
		bge $t0, 10, iterate_through__end	                    # if the counter is greater than the known length, goto end
		mul $t1, $t0, 4				                            # add linearly to the current address
							                                    # (start with the address of the first item, and add on)
							                                    # each word is 2 bytes, but the computer is 4-byte aligned
		lw $t2, array($t1)			                            # (l)oad the (w)ord from the recorded address 

iterate_through_array__print:
		move $a0, $t2				                            # |
		li $v0, 1				                                # |
		syscall					                                # |

		li $v0, 11				                                # |
		li $a0, '\n'				                            # | print 
		syscall					                                # |

		addi $t0, $t0, 1			                            # |
		j iterate_through_array__for_loop	                    # |
            
iterate_through__end:
		pop $ra					                                # retrieve the return address
		end					                                    # exit stack frame
		jr $ra					                                # return

main__epilogue:
		jr $ra
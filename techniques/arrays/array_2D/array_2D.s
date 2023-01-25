# constants
ARRAY_COLUMN = 10
ARRAY_ROW = 10

# initialising the array with a label
# so an abstracted address to some allocated section in memory
# for a 2D array, we 'linearise' or 'flatten' the 2D array, so this comes the 'area' of the array 
	.data
array:	.space ARRAY_COLUMN * ARRAY_ROW

	.text
# a 2D array is like a grid, with rows and columsn
# iterate through a 2D array and print each value... we should see a square

main:
iterating_through_2D_array__prologue:      
        begin                                           		        # begins a new stack frame        
        push    $ra                                     		        # store $ra 
        
iterating_through_2D_array__body:
        li      $t0, 0                                  		        # int current row = 0   
				li      $t2, ARRAY_ROW                       		    # load the number of rows to $t2     
				li      $t3, ARRAY_COLUMN                        		# load the number of columns to $t3
	 
iterating_through_2D_array__for_row:
        bge     $t0, $t2, iterating_through_2D_array__epilogue		    # while (the current row < total number of rows) {
        li      $t1, 0                                  		        # int current col = 0
				j       iterating_through_2D_array__for_col
	
iterating_through_2D_array__for_col:
        bge     $t1, $t3, iterating_through_2D_array__for_col_post      # while (current col < total number of columns) {
        mul     $t5, $t0, ARRAY_COLUMN               			         
        add     $t5, $t5, $t1                           		       
								# EXPLANAION:
								# the adress of array[row][col] = current row * size of each row + current column							                   
								# ( * 1 because each value is only 1 byte)
								# so the key here is we are flattening out the array;
								# counting how many blocks or data values we are from the start by
								# counting first left to right, then top to bottom
        
				mul	$t8, $t0, 10					                     # |
				add	$t8, $t8, $t1						                 # | initialising values to demonstrate row|column
				sb	$t8, array($t5)						                 # |
        lb      $a0, array($t5)                      			         # retrieve the value at that address
				li 	$v0, 1				                           		 # |
				syscall								                     # | print
        li $v0, 11				                          			     # |
				li $a0, ' '				                	        	 # | print 
				syscall	
	
        addi    $t1, $t1, 1                             		        # move to the next 'column'
        j       iterating_through_2D_array__for_col               	    # }

iterating_through_2D_array__for_col_post:
        addi    $t0, $t0, 1                             		        # move to the next 'row'
	
				li $v0, 11				                                # |
				li $a0, '\n'				                	        # | print 
				syscall								              	    # |
	
        j       iterating_through_2D_array__for_row               	    # }
        
iterating_through_2D_array__epilogue:	
				pop     $ra                                     		# retrieves $ra
				end                                             		# ends the current stack frame
				jr      $ra		                        		        # return;

main__epilogue:
				jr	$ra
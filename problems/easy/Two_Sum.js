// Note that this file will not execute. It is for demonstrative purposes.

// The code below finds two numbers in an array that sum to a target number
// and returns [index of number 1 in array, index of nubmer 2 in array].

// Using a hashmap, this can be done in O(n) time.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    // A hash map is a data structure that implements an associative array.
    // That is; a dictionary or data structure that holds key:value data pairs.
    // In this case, the key is the complement, and the value is the corresponding index; {c:i}.
    const hash = {};
    for (let i = 0; i < nums.length; i++) {
        let c = target - nums[i];
        
        // If the complement (number needed to bring the current number to 10) is already
        // registered as a key in the hash, then return...
        if (c in hash) return [hash[c], i];
        
        // Otherwise, register the number in the hash with its index as the value.
        hash[nums[i]] = i;
    }
    return [];
};
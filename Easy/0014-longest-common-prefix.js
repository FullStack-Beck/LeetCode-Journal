/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    var prefix = strs[0]

    for(let i = 1; i < strs.length; i++) {
        
        while(strs[i].indexOf(prefix) != 0) {
            var prefix = prefix.substring(0, prefix.length - 1)
        }
    }
    return prefix;
};
/* 
I cooked this up to see if i could easily convert my java code, into .js cause i've been using lots of JS. 
I had one problem, which was just me forgetting that the for loop is for each string not for each character in each string. 
*/

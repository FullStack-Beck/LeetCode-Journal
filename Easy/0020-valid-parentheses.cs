public class Solution {
    public bool IsValid(string s) {

        Stack<char> stack = new Stack<char>();

        foreach(char c in s) {
            if(c == '(' || c == '{' || c == '[' )
            {
                stack.Push(c);
            }
            else if(c == ')' || c == '}' || c == ']') 
            {
                if (stack.Count == 0) return false;

                char top = stack.Pop();

                if( c == ')' && top != '(' ) return false;
                if( c == '}' && top != '{' ) return false;
                if( c == ']' && top != '[' ) return false;
            }
        }
        
        return stack.Count == 0;
        
        /* this solution worked for the 5 test cases but broke after multiple trailing brackets for example {} }{ so it picked up the first with index and didnt even see the second broken one
        if(s.IndexOf('(') < s.IndexOf(')') && s.IndexOf('(') != -1) {
            if(s.IndexOf('{') > s.IndexOf('(') && s.IndexOf('}') < s.IndexOf(')') || s.IndexOf('[') > s.IndexOf('(') && s.IndexOf(']') < s.IndexOf(')') ) {
                return true;
            }
            else if(s.IndexOf('{') == null && s.IndexOf('}') == null && s.IndexOf('[') == null && s.IndexOf(']') == null )
            {
                return true;
            }
            else if(s.IndexOf('{') > s.IndexOf('(') && s.IndexOf('{') < s.IndexOf(')') && s.IndexOf('}') > s.IndexOf(')') || s.IndexOf('[') > s.IndexOf('(') && s.IndexOf('[') < s.IndexOf(')') && s.IndexOf(']') > s.IndexOf(')') ) {
                return false;
            }
            else { return true; }
        }
        if(s.IndexOf('{') < s.IndexOf('}') && s.IndexOf('{') != -1) {
            if(s.IndexOf('(') > s.IndexOf('{') && s.IndexOf(')') < s.IndexOf('}') || s.IndexOf('[') > s.IndexOf('{') && s.IndexOf(']') < s.IndexOf('}') ) {
                return true;
            }
            else if(s.IndexOf('(') == null && s.IndexOf(')') == null && s.IndexOf('[') == null && s.IndexOf(']') == null )
            {
                return true;
            }
            else if(s.IndexOf('(') > s.IndexOf('{') && s.IndexOf('(') < s.IndexOf('}') && s.IndexOf(')') > s.IndexOf('}') || s.IndexOf('[') > s.IndexOf('{') && s.IndexOf('[') < s.IndexOf('}') && s.IndexOf(']') > s.IndexOf('}') ) {
                return false;
            }
            else { return true; }
        }
        if(s.IndexOf('[') < s.IndexOf(']') && s.IndexOf('[') != -1) {
            if(s.IndexOf('{') > s.IndexOf('[') && s.IndexOf('}') < s.IndexOf(']') || s.IndexOf('(') > s.IndexOf('[') && s.IndexOf(')') < s.IndexOf(']') ) {
                return true;
            }
            else if(s.IndexOf('{') == null && s.IndexOf('}') == null && s.IndexOf('(') == null && s.IndexOf(')') == null )
            {
                return true;
            }
            else if(s.IndexOf('{') > s.IndexOf('[') && s.IndexOf('{') < s.IndexOf(']') && s.IndexOf('}') > s.IndexOf(']') || s.IndexOf('(') > s.IndexOf('[') && s.IndexOf('(') < s.IndexOf(']') && s.IndexOf(')') > s.IndexOf(']') ) {
                return false;
            }
            else { return true; }
        }
        else {return false;}
        */
    }
}

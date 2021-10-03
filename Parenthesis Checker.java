//https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
class Parenthesis
{
    // Function to return if the paranthesis are balanced or not
    static boolean ispar(String x)
    {
        LinkedList<Character> stack = new LinkedList<>();
        int lenOfExpr = x.length();
        for(int i = 0 ; i < lenOfExpr; i++) {
            char curr = x.charAt(i);
            if(curr == '{' || curr == '[' || curr == '(') {
                stack.push(curr);
            }
            else if(curr == '}' && !stack.isEmpty() && stack.peek() == '{') {
                stack.pop();
            }
            else if(curr == ')' && !stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            }
            else if(curr == ']' && !stack.isEmpty() && stack.peek() == '[') {
                stack.pop();
            }
            else {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
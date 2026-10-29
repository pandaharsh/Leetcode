class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        sol(2*n,0,0,"",list);
        return list;
    }
    public void sol(int n,int ob,int cb,String ans,List<String> list){
        if(cb>ob) return;
        if(ob>n/2) return;
        if(ob+cb==n){
            list.add(ans);
        }
        sol(n,ob+1,cb,ans+"(",list);
        sol(n,ob,cb+1,ans+")",list);
    }
}
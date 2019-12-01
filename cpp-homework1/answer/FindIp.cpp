/*
回溯
 */

#include<iostream>
#include<string>

using namespace std;

int main() {
  string ip;
  std::


	std::cout<<maxSum(array)<<endl;
	system("pause");
}

var restoreIpAddresses = function(str) {
  // 保存所有符合条件的IP地址
  let res = [];
  // 递归函数
  let search = (cur, sub) => {
    // 如果剩下的位数超过12位，就说明是非法的
    if(sub.length > 12) return 
    // 边界条件，已经分完一种情况了，就将它push到res中
    if(cur.length === 4 && cur.join("") === str){
      res.push(cur.join('.'))
    }else{
      // 还没分完。正常处理情况
      // 如果剩下的数字不到3个了，就按照剩下的循环；否则按照三位循环
      for(let i=0, len=Math.min(3, sub.length), tmp; i<len; i++){
        // 取出从0开始，i+1长度的子串，也就是1~len的子串
        tmp = sub.substr(0, i+1)
        // 对取出的子串验证是否合法
        if(tmp-256 < 0){  // 小于255合法
          // 将这个合法的数字格式化（去掉前面的0），递归调用，进行下一次
          search(cur.concat([tmp * 1]), sub.substr(i + 1))
        }
      }
    }
  }
  // 第一次调用
  search([], str)
  return res
};

vector<string> restoreIpAddresses(string &s, int count, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		if (count == 0 && i != len - 1) continue;
		if ((len - i - 1) > (count * 3)) continue;
		if ((len - i - 1) < (count * 1)) continue;
		
		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;
		if (to_string(ip) != sub) break;

		if (count == 0)
		{
			ret.push_back(sub);
		}
		vector<string> vs = restoreIpAddresses(s, count - 1, i + 1);
		for (auto &v : vs)
		{
			ret.push_back(sub + "." + v);
		}
	}
	return ret;
}

// cur : 当前答案，以 String List的形式，最后再join成String形式 例如 [[255],[255],[111],[35]] -> 255.255.111.35
    // pos, 当前扫描到的s的位置， ans最终答案
    private void backtracking(String s, int pos, List<String> cur,  List<String> ans) {
        if (cur.size() >= 4) {
            if (pos == s.length()) ans.add(String.join(".", cur));
            return;
        }
        // 分割得到ip地址的一段后，下一段只能在长度1-3范围内选择
        for (int i = 1; i <= 3; i++) {
            if (pos+i > s.length()) break;
            String segment = s.substring(pos, pos+i);
            // 剪枝条件：不能以0开头，不能大于255
            if (segment.startsWith("0") && segment.length() > 1 || (i == 3 && Integer.parseInt(segment) > 255)) continue;
            cur.add(segment);
            // 注意此处传的参数
            backtracking(s, pos+i, cur, ans);
            cur.remove(cur.size()-1);
        }
    }
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        backtracking(s, 0, new ArrayList<>(), ans);
        return ans;
    }

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        res = []
		# 判读是否满足ip的条件
        def helper(tmp):
            if not tmp or (tmp[0] == "0" and len(tmp) > 1) or int(tmp) > 255:
                return False
            return True
		# 三个循环,把数字分成四份
        for i in range(3):
            for j in range(i + 1, i + 4):
                for k in range(j + 1, j + 4):
                    if i < n and j < n and k < n:
                        tmp1 = s[:i + 1]
                        tmp2 = s[i + 1:j + 1]
                        tmp3 = s[j + 1:k + 1]
                        tmp4 = s[k + 1:]
                        # print(tmp1, tmp2, tmp3, tmp4)

                        if all(map(helper, [tmp1, tmp2, tmp3, tmp4])):
                            res.append(tmp1 + "." + tmp2 + "." + tmp3 + "." + tmp4)
        return res


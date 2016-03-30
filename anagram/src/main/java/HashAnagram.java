import java.util.*;

public class HashAnagram implements Anagram {

	private static Map<Character, Integer> buildCountMap(char [] str) {
		Map<Character, Integer> countMap = new HashMap<>();

		for(int i = 0; i < str.length; i++) {
			int count = 0;
			if(countMap.containsKey(str[i])) {
				count = countMap.get(str[i]);
			}
			countMap.put(str[i], count+1);
		}

		return countMap;
	}
	
	public boolean anagram(char [] a, char [] b) {
		Map<Character, Integer> acount = buildCountMap(a);
		Map<Character, Integer> bcount = buildCountMap(b);

		if(acount.size() != bcount.size()) {
			return false;
		}

		for(Map.Entry<Character, Integer> aEntry : acount.entrySet()) {
			char ch = aEntry.getKey();
			if(!bcount.containsKey(ch)) {
				return false;
			}
			if(aEntry.getValue() != bcount.get(ch)) {
				return false;
			}
		}


		return true;
	}

}

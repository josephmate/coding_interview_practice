import java.util.*;

public class DataStructAllUniqueChars implements AllUniqueChars {
	
	public boolean allUniqueChars(char [] str){
		Set<Character> set = new HashSet<>();
		for(char c : str) {
			if(set.contains(c)) {
				return false;
			}
			set.add(c);
		}
		return true;
	}

}

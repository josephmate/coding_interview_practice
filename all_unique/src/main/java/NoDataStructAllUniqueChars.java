import java.util.*;

public class NoDataStructAllUniqueChars implements AllUniqueChars {
	
	public boolean allUniqueChars(char [] str){
		if(str.length == 0){
			return true;
		}

		Arrays.sort(str);
		
		for(int i = 1; i < str.length; i++) {
			if( str[i] == str[i-1] ) {
				return false;
			}
		}


		return true;
	}

}

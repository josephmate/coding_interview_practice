
import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestNoDataStructAllUniqueChars extends TestAllUniqueChars {

	public AllUniqueChars getImpl() {
		return new NoDataStructAllUniqueChars();
	}

}

import java.util.*;

import javafx.application.*;
import javafx.stage.*;
import javafx.scene.paint.Color;

public class Main extends Application {
	

	public static void main(String []args) {
		Application.launch(args);

	}
	
	@Override
	public void start(Stage primaryStage) {
		List<String> args =getParameters().getRaw();
		if(args.size() != 1) {
			throw new IllegalArgumentException(
					"./runjar.sh radius");
		}
		int argCounter = 0;
		int radius = Integer.parseInt(args.get(argCounter++));
		
		canvas.getGraphicsContext2D().setFill(Color.White);
		canvas.getGraphicsContext2D().fillRect(0, 0, 1, 1);

		primaryStage.show();
	}


  private void setPixel(int x, int y){
		canvas.getGraphicsContext2D().getPixelWriter().setColor(x, y,Color.Black);
	}

	private void drawEighthOfCircle( int radius ){
	}

}


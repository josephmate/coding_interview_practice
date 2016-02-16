import java.util.*;

import javafx.application.*;
import javafx.stage.*;
import javafx.scene.paint.Color;

import javafx.scene.*;
import javafx.scene.paint.*;
import javafx.scene.canvas.*;


public class Main extends Application {
	

	public static void main(String []args) {
		Application.launch(args);

	}
	
	private static final int HEIGHT = 300;
	private static final int WIDTH = 300;
	private GraphicsContext gc;
	@Override
	public void start(Stage primaryStage) {
		List<String> args =getParameters().getRaw();
		if(args.size() != 1) {
			throw new IllegalArgumentException(
					"./runjar.sh radius");
		}
		int argCounter = 0;
		int radius = Integer.parseInt(args.get(argCounter++));
		

		Group root = new Group();
		Scene s = new Scene(root, WIDTH, HEIGHT, Color.BLACK);

		final Canvas canvas = new Canvas(WIDTH, HEIGHT);
		gc = canvas.getGraphicsContext2D();
		 
		gc.setFill(Color.WHITE);
		gc.fillRect(0, 0, WIDTH, HEIGHT);
		gc.setFill(Color.BLACK);
		gc.strokeLine(WIDTH/2, 0, WIDTH/2, HEIGHT);
		gc.strokeLine(0, HEIGHT/2, WIDTH, HEIGHT/2);
		 
		root.getChildren().add(canvas);
		
		drawEighthOfCircle(radius);

		primaryStage.setScene(s);
		primaryStage.show();
	}

	/**
	 * x = 0, y = 0, is the middle
	 */
  private void setPixel(int x, int y){
		gc.getPixelWriter().setColor(WIDTH/2 + x, HEIGHT/2 - y, Color.BLACK);
	}

	private void drawEighthOfCircle( int radius ){
		//TODO implement
		setPixel(radius, radius);
		setPixel(radius-1, radius);
		for(int i = 1; i <= 10; i++) {
			setPixel(radius+i, radius);
		}
		setPixel(radius, radius-1);
		for(int i = 1; i <= 5; i++) {
			setPixel(radius, radius+i);
		}
	}

}


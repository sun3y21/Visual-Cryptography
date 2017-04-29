/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Sunnny
 */
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import javax.swing.JComponent;
 
public class ZoomableImage extends JComponent {
 
    private float scaleFactor;
     
    private BufferedImage originalImage;
 
    public ZoomableImage() {
        this.scaleFactor = 1;
        this.setSize(0, 0);
        setBackground(Color.WHITE);
    }
 
    public void setImage(BufferedImage image) {
        this.originalImage = image;
        this.setSize(image.getWidth(),image.getHeight());
    }
 
    public void setScaleFactor(float scaleFactor) {
        this.scaleFactor = scaleFactor;
        this.repaint();
    }
 
    @Override
    public void paintComponent(Graphics g) {
        if (this.originalImage != null) {
            Graphics2D g2 = (Graphics2D) g;
            int newW = (int) (originalImage.getWidth() * scaleFactor);
            int newH = (int) (originalImage.getHeight() * scaleFactor);
            this.setPreferredSize(new Dimension(newW, newH));
            this.revalidate();
            g2.drawImage(originalImage, 0, 0, newW, newH, null);
        }
    }
}
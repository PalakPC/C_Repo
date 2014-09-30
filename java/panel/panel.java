//Java program to display multiple windows with buttons to maneuver between them.

package panel;

import java.awt.*;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class panel extends JPanel {
   public static JFrame frame1;
   public JFrame frame2;
   public JFrame frame3;

   class Panel1 extends JPanel implements ActionListener {
      private JButton jcomp1;	

      public Panel1() {
         jcomp1 = new JButton("Next");
         setPreferredSize(new Dimension(400, 200));
         setLayout(null);
         add(jcomp1);
         jcomp1.setBounds(150, 75, 100, 30);
         jcomp1.addActionListener(this);
      }

      public void actionPerformed(ActionEvent e) {
         frame2 = new JFrame("Window 2");
         frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         frame2.getContentPane().add(new Panel2());
         frame2.pack();
         frame2.setVisible(true);
         frame1.setVisible(false);
      }
   }

   class Panel2 extends JPanel implements ActionListener {
      private JButton jcomp1;
      private JButton jcomp2;

      public Panel2() {
         jcomp1 = new JButton("Previous");
         jcomp2 = new JButton("Next");
         setPreferredSize(new Dimension(400, 200));
         setLayout(null);
         add(jcomp1);
         add(jcomp2);
         jcomp1.setBounds(75, 75, 100, 30);
         jcomp2.setBounds(225, 75, 100, 30);
         jcomp1.addActionListener(this);
         jcomp2.addActionListener(this);
      }

      public void actionPerformed(ActionEvent e) {
         if(e.getSource() == jcomp1) {
            frame1 = new JFrame("Window 1");
            frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame1.getContentPane().add(new Panel1());
            frame1.pack();
            frame1.setVisible(true);
         }               
         else {
            frame3 = new JFrame("Window 3");
            frame3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame3.getContentPane().add(new Panel3());
            frame3.pack();
            frame3.setVisible(true);
         }
         frame2.setVisible(false);
      }
   }

   class Panel3 extends JPanel implements ActionListener {
      private JButton jcomp1;

      public Panel3() {
         jcomp1 = new JButton("Previous");
         setPreferredSize(new Dimension(400, 200));
         setLayout(null);
         add(jcomp1);
         jcomp1.setBounds(150, 75, 100, 30);
         jcomp1.addActionListener(this);
      }
		
      public void actionPerformed(ActionEvent e) {
         frame2 = new JFrame("Window 2");
         frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         frame2.getContentPane().add(new Panel2());
         frame2.pack();
         frame2.setVisible(true);
         frame3.setVisible(false);
      }
   }

   Panel1 makepanel1() {
      return new Panel1();
   }

   public static void main(String[] args) {
      frame1 = new JFrame("Window 1");
      panel x;
      x = new panel();
      frame1.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
      frame1.getContentPane().add(x.makepanel1());
      frame1.pack();
      frame1.setVisible(true);
   }
}

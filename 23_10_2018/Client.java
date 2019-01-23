

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.Socket;

import org.xml.sax.InputSource;

public class Client {
	
	public static void main(String args[]){
		
		Socket c=null;
		int mx=63300;
		
		byte[] bytearr=new byte[mx];
		
		try {
			c=new Socket("localhost",8025);
			
			//receive the file
			InputStream is=(c.getInputStream());
			
			FileOutputStream fos=new FileOutputStream("hello.txt");
			BufferedOutputStream bos=new BufferedOutputStream(fos);
			
			int cur=is.read(bytearr,0,mx);
			
			int bytesread=cur;
			
			do {
				bytesread=is.read(bytearr,cur,mx-cur);
				
				if(bytesread>=0)
					cur+=bytesread;
				
			} while (bytesread>-1);
			
			bos.write(bytearr,0,cur);
			c.close();
			
			
		} catch (Exception e) {
			System.out.print(e);
			// TODO: handle exception
		}
		
		
		
	}
}

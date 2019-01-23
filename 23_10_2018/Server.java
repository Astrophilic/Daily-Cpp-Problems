
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	
	public static void main(String args[]){
		ServerSocket s = null;
		try {
			 s=new ServerSocket(8025);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			Socket c=s.accept();
			
			File f=new File("hellos.txt");
			
			byte[] bytearr=new byte[(int) f.length()];
			
			FileInputStream fis=new FileInputStream(f);
			BufferedInputStream bis=new BufferedInputStream(fis);
			
			bis.read(bytearr,0,bytearr.length);
			OutputStream os=c.getOutputStream();
			
			os.write(bytearr,0,bytearr.length);
			
			
			s.close();
			os.close();
			
			
			
		} catch (Exception e) {
			// TODO: handle exception
			System.out.print(e);
			
		}
		
		
	}
}

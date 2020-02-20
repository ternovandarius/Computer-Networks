package UDP;

import java.io.*;
import java.net.*;

public class Client {

	public static void main(String args[]) throws IOException {
		DatagramSocket clientSocket = new DatagramSocket();
		InetAddress IPAddress = InetAddress.getByName("localhost");
		byte buf[]=new byte[5];
		String s="12345";
		buf=s.getBytes();
		InetAddress ip = InetAddress.getLocalHost();
		DatagramPacket sendPacket = new DatagramPacket(buf, 5, ip, 777);
		clientSocket.send(sendPacket);
	}
}
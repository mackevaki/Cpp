import java.util.ArrayList;

public class Node {
    private String nodeIpAddress;
    private int mask;

    private ArrayList <String> neighbIps;

    public Node(String ipAddress) {
        this.nodeIpAddress = ipAddress;
    }

    public String getAddress() {
        return nodeIpAddress;
    }

    //public void addNeighb(String ip) { neighbs.add(ip);}

    public void getSubnetAddress(String nodeIpAddress) {
        String[] currentSe;
        /* Место для того, чтобы заменить все на методы из SubnetUtils.SubnetInfo*/
        nodeIpAddress.replaceAll("/", "\\.");
        currentSe = nodeIpAddress.split("\\.");
        int prefix = Integer.parseInt(currentSe[4]);
        byte [] byteAddress = new byte[4];
        for (int i = 0; i < 4; i++)
            byteAddress[i] = (byte)Integer.parseInt(currentSe[i], 10);

        int maskValue = 0xffffffff << (32 - prefix);
        byte[] netAddress = new byte[4];
        byte[] mask = new byte[]{ (byte)(maskValue >>> 24), (byte)(maskValue >> 16 & 0xff), (byte)(maskValue >> 8 & 0xff), (byte)(maskValue & 0xff) };

        for (int i = 0; i < netAddress.length; i++)
            netAddress[i] = (byte)(byteAddress[i] & mask[i]);


    }

    public static void toBinary(byte[] bytes) {
        String currentBinary;
        for (byte aByte : bytes) {
            currentBinary = Integer.toBinaryString(256 + (int) aByte);
            System.out.print(currentBinary.substring(currentBinary.length()-8)+" ");
        }
    }

}


import java.util.HashMap;

public class Subnet {
    public HashMap <String, Node> nodes = new HashMap <String, Node>();
    public String ipSubnet;

    public Node getNodeWithIp(String nodeIp) {
        return nodes.get(nodeIp);
    }

}

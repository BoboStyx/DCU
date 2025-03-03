import java.util.*;

class CellTower {
    String id;
    int x, y, radius;
    String operator = null;
    Set<Client> connectedClients = new HashSet<>();

    public CellTower(String towerid, int x, int y, int rad) {
        this.id = towerid;
        this.x = x;
        this.y = y;
        this.radius = rad;
    }

    public boolean isInRange(Client client) {
        return this.getDistance(client.x, client.y) <= this.radius;
    }

    public double getDistance(int x, int y) {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }

}

class Operator {
    String name;
    Set<Client> clients = new HashSet<>();
    Set<CellTower> towers = new HashSet<>();

    public Operator(String name) {
        this.name = name;
        }
}


class Client {
    String number;
    int x, y;
    Operator registeredOperator;
    CellTower connectedTower = null;

    public Client(String number, Operator operator, int x, int y) {
        this.number = number;
        this.x = x;
        this.y = y;
        this.registeredOperator = operator;
    }
}


class Network {

    Map<String, Client> clients = new HashMap<>();
    Map<String, Operator> operators = new HashMap<>();
    Map<String, CellTower> towers = new HashMap<>();

    public void addTower(String id, int x, int y, int radius) {
        towers.put(id, new CellTower(id, x, y, radius));
    }

    public void addOperator(String name) {
        operators.put(name, new Operator(name));
    }
    public void addClient(String number, String operatorName, int x, int y) {
        Operator operator = operators.get(operatorName);
        if (operator == null) {
            return;
        }
        Client client = new Client(number, operator, x, y);
        clients.put(number, client);
        operator.clients.add(client);
        connectToNearestTower(client);
    }

    public void moveClient(String number, int x, int y) {
        Client client = clients.get(number);
        if (client == null) {
            return;
        }
        client.x = x;
        client.y = y;
        if (client.connectedTower == null || client.connectedTower.radius < client.connectedTower.getDistance(client.x, client.y)) {
            connectToNearestTower(client);
        }
    }

    public void changeOperator(String number, String newOperator) {
        Client client = clients.get(number);
        Operator operator = operators.get(newOperator);
        if (client == null || operator == null) {
            return;
		}

        client.registeredOperator.clients.remove(client);
        client.registeredOperator = operator;
        client.registeredOperator.clients.add(client);
        connectToNearestTower(client);
    }
    public int towerClientCount(String towerid) {
        return towers.getOrDefault(towerid, new CellTower("0", 0, 0, 0)).connectedClients.size();
    }

    public int operatorSubscriberCount(String name) {
        return operators.getOrDefault(name, new Operator("")) .clients.size();
    }

    public void removeClient(String name) {
        Client client = clients.remove(name);
        if (client == null) {
            return;
        }
        client.registeredOperator.clients.remove(client);
        if (client.connectedTower != null) {
            client.connectedTower.connectedClients.remove(client);
        }
    }

    public void removeTower(String towerid) {
        CellTower tower = towers.remove(towerid);
        if (tower == null) {
            return;
        }
        for (Client client : new HashSet<>(tower.connectedClients)) {
            client.connectedTower = null;
            connectToNearestTower(client);
        }
    }

    public void countNoSignalClients() {
        for (Operator operator : operators.values()) {
            int count = 0;
            for (Client client : operator.clients) {
                if (client.connectedTower == null) {
                    count += 1;
                }
            }
            System.out.println(operator.name + ": " + count + " phones without signal.");
        }
    }

    public void registerOperatorTower(String operatorName, String towerid) {
        Operator operator = operators.get(operatorName);
        CellTower tower = towers.get(towerid);
        if (tower == null || operator == null) {
            return;
        }
        operator.towers.add(tower);
        tower.operator = operatorName;
    }


    public void connectToNearestTower(Client client) {
        CellTower closest = null;
        double bestDistance = Double.MAX_VALUE;
        for (CellTower tower : towers.values()) {
            if (tower.operator != null && tower.operator.equals(client.registeredOperator.name) && tower.isInRange(client)) {
                double distance = tower.getDistance(client.x, client.y);
                if (distance < bestDistance || (distance == bestDistance && tower.connectedClients.size() < closest.connectedClients.size())) {
                    closest = tower;
                    bestDistance = distance;
                }
            }
        }
        if (client.connectedTower != null) {
            client.connectedTower.connectedClients.remove(client);
        }
        if (closest != null) {
            closest.connectedClients.add(client);
        }
        client.connectedTower = closest;
    }
}

public class NetworkSimulation {
     public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);
         Network network = new Network();

         while (scanner.hasNext()) {
             String command = scanner.next();
             switch (command) {
                 case "ADD_TOWER":
                     network.addTower(scanner.next(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
                     break;
                 case "ADD_OPERATOR":
                     network.addOperator(scanner.next());
                     break;
                 case "ADD_CLIENT":
                     network.addClient(scanner.next(), scanner.next(), scanner.nextInt(), scanner.nextInt());
                     break;
                 case "MOVE_CLIENT":
                     network.moveClient(scanner.next(), scanner.nextInt(), scanner.nextInt());
                     break;
                 case "CHANGE_OPERATOR":
                     network.changeOperator(scanner.next(), scanner.next());
                     break;
                 case "REGISTER_OPERATOR_TOWER":
                     network.registerOperatorTower(scanner.next(), scanner.next());
                     break;
                 case "REMOVE_TOWER":
                     network.removeTower(scanner.next());
                     break;
                 case "REMOVE_CLIENT":
                     network.removeClient(scanner.next());
                     break;
                 case "TOWER_CLIENT_COUNT":
                     System.out.println(network.towerClientCount(scanner.next()));
                     break;
                 case "OPERATOR_SUBSCRIBER_COUNT":
                     System.out.println(network.operatorSubscriberCount(scanner.next()));
                     break;
                 case "NO_SIGNAL_COUNT":
                     network.countNoSignalClients();
                     break;
             }
         }
         scanner.close();
     }
 }

import java.util.*;

public class NetworkSimulation{

    static class CellTower {
        private String towerId;
        private int x, y, coverageRadius;
        private Operator operator;
        private Set<String> clients;

        public CellTower(String towerId, int x, int y, int coverageRadius) {
            this.towerId = towerId;
            this.x = x;
            this.y = y;
            this.coverageRadius = coverageRadius;
            this.operator = null;
            this.clients = new HashSet<>();
        }

        public String getTowerId() { return towerId; }
        public int getX() { return x; }
        public int getY() { return y; }
        public int getCoverageRadius() { return coverageRadius; }
        public Set<String> getClients() { return clients; }

        public void setOperator(Operator operator) {
            this.operator = operator;
            operator.registerTower(this);
        }
        public boolean isWithinRange(int clientX, int clientY) {
            double distance = Math.sqrt(Math.pow((clientX - x), 2) + Math.pow((clientY - y), 2));
            return distance <= coverageRadius;
        }

        public void addClient(String clientPhone) { clients.add(clientPhone); }
        public void removeClient(String clientPhone) { clients.remove(clientPhone); }
    }

    static class Operator {
        private String name;
        private Set<Client> clients;
        private Set<CellTower> towers;

        public Operator(String name) {
            this.name = name;
            this.clients = new HashSet<>();
            this.towers = new HashSet<>();
        }

        public String getName() { return name; }

        public void registerClient(Client client) { clients.add(client); }
        public void registerTower(CellTower tower) { towers.add(tower); }

        public int getSubscriberCount() { return clients.size(); }

        public int getNoSignalCount() {
            int count = 0;
            for (Client client : clients) {
                if (!client.hasSignal()) {
                    count++;
                }
            }
            return count;
        }

        public Set<CellTower> getTowers() { return towers; }
    }
    static class Client {
        private String phoneNumber;
        private Operator operator;
        private int x, y;
        private CellTower connectedTower;

        public Client(String phoneNumber, Operator operator, int x, int y) {
            this.phoneNumber = phoneNumber;
            this.operator = operator;
            this.x = x;
            this.y = y;
            this.connectedTower = null;
            operator.registerClient(this);
            connectToNearestTower();
        }

        public String getPhoneNumber() { return phoneNumber; }
        public Operator getOperator() { return operator; }

        public void move(int newX, int newY) {
            this.x = newX;
            this.y = newY;
            connectToNearestTower();
        }

        public void changeOperator(Operator newOperator) {
            this.operator = newOperator;
            connectToNearestTower();
        }

        public boolean hasSignal() { return connectedTower != null; }

        public void connectToNearestTower() {
            CellTower nearestTower = null;
            double minDistance = Double.MAX_VALUE;

            for (CellTower tower : operator.getTowers()) {
                if (tower.isWithinRange(x, y)) {
                    double distance = Math.sqrt(Math.pow((x - tower.getX()), 2) + Math.pow((y - tower.getY()), 2));
                    if (distance < minDistance) {
                        nearestTower = tower;
                        minDistance = distance;
                    }
                }
            }

            if (nearestTower != null) {
                if (connectedTower != null) {
                    connectedTower.removeClient(phoneNumber);
                }
                connectedTower = nearestTower;
                connectedTower.addClient(phoneNumber);
            }
        }
    }

    static class Network {
        private Map<String, Operator> operators;
        private Map<String, Client> clients;
        private Map<String, CellTower> towers;

        public Network() {
            this.operators = new HashMap<>();
            this.clients = new HashMap<>();
            this.towers = new HashMap<>();
        }

        public void addOperator(String name) { operators.put(name, new Operator(name)); }

        public void addTower(String id, int x, int y, int coverageRadius) {
            towers.put(id, new CellTower(id, x, y, coverageRadius));
        }

        public void addClient(String phoneNumber, String operatorName, int x, int y) {
            if (!operators.containsKey(operatorName)) {
                System.out.println("Operator does not exist.");
                return;
            }
            Client client = new Client(phoneNumber, operators.get(operatorName), x, y);
            clients.put(phoneNumber, client);
        }

        public void moveClient(String phoneNumber, int newX, int newY) {
            if (clients.containsKey(phoneNumber)) {
                clients.get(phoneNumber).move(newX, newY);
            }
        }

        public void changeOperator(String phoneNumber, String newOperatorName) {
            if (clients.containsKey(phoneNumber) && operators.containsKey(newOperatorName)) {
                clients.get(phoneNumber).changeOperator(operators.get(newOperatorName));
            }
        }

        public int getTowerClientCount(String towerId) {
            return towers.containsKey(towerId) ? towers.get(towerId).getClients().size() : 0;
        }

        public int getOperatorSubscriberCount(String operatorName) {
            return operators.containsKey(operatorName) ? operators.get(operatorName).getSubscriberCount() : 0;
        }

        public void registerOperatorTower(String operatorName, String towerId) {
            if (operators.containsKey(operatorName) && towers.containsKey(towerId)) {
                towers.get(towerId).setOperator(operators.get(operatorName));
            }
        }

        public void removeClient(String phoneNumber) {
            clients.remove(phoneNumber);
        }

        public void removeTower(String towerId) {
            towers.remove(towerId);
        }

        public int getNoSignalCount(String operatorName) {
            return operators.containsKey(operatorName) ? operators.get(operatorName).getNoSignalCount() : 0;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Network network = new Network();

        while (scanner.hasNext()) {
            String command = scanner.next();
            switch (command) {
                case "ADD_OPERATOR":
                    network.addOperator(scanner.next());
                    break;
                case "ADD_TOWER":
                    network.addTower(scanner.next(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
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
                case "TOWER_CLIENT_COUNT":
                    System.out.println(network.getTowerClientCount(scanner.next()));
                    break;
                case "OPERATOR_SUBSCRIBER_COUNT":
                    System.out.println(network.getOperatorSubscriberCount(scanner.next()));
                    break;
                case "REGISTER_OPERATOR_TOWER":
                    network.registerOperatorTower(scanner.next(), scanner.next());
                    break;
                case "REMOVE_CLIENT":
                    network.removeClient(scanner.next());
                    break;
                case "REMOVE_TOWER":
                    network.removeTower(scanner.next());
                    break;
                case "NO_SIGNAL_COUNT":
                    System.out.println(network.getNoSignalCount(scanner.next()));
                    break;
                default:
                    System.out.println("Invalid Command");
            }
        }

        scanner.close();
    }
}

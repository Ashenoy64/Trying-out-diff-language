class Employee_client {
	public static void main(String[] args) {
		Employee model = getfromDatabase();
		EmployeeView view = new EmployeeView();
		EmployeeController controller = new EmployeeController(model, view);
		controller.updateview();

		controller.setName("vinaypadegal");
		controller.updateview();

	}

	public static Employee getfromDatabase() {
		Employee e = new Employee();
		e.setName("vinay");
		e.setId("abc123");
		e.setDept("CSE");
		return e;

	}
}
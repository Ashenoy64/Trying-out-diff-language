class EmployeeController
{
		private Employee model;
		private EmployeeView view;
		EmployeeController(Employee model,EmployeeView view)
		{
			this.model = model;
			this.view = view;
		}
		public void setName(String name)
		{
			model.setName(name);
		}
		public void setId(String id)
		{
			model.setId(id);
		}
		public void setDept(String dept)
		{
			model.setDept(dept);
		}
		public String getName()
		{
			return model.getName();
		}
		public String getId()
		{
			return model.getId();
		}
		public String getDept()
		{
			return model.getDept();
		}
		
		void updateview()
		{
			view.display(getName(),getId(),getDept());
		}
		
		
		
}
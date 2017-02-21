using UnityEngine;
using System.Collections;

public class roket : MonoBehaviour {

    

    Rigidbody2D roketrigidbody;
    float alivetime = 2f;
    public GameObject carpismaefektparticle;




	void Start () {

        roketrigidbody = GetComponent<Rigidbody2D>();
        Destroy(gameObject, alivetime);

    }
	
	
	void Update ()
    {

       
        if(transform.localRotation.z<0)
        {
            roketrigidbody.AddForce(new Vector2(100, 0));
        }
        if(transform.localRotation.z>0)
        {
            roketrigidbody.AddForce(new Vector2(-100, 0));
        }

	}

    void OnTriggerEnter2D()
    {
        Instantiate(carpismaefektparticle, transform.position, transform.rotation);
        Destroy(gameObject);
    }

    //particle clone objesini destroyme scriptini particleye atayarak yok ettik


}

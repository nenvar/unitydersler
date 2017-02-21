using UnityEngine;
using System.Collections;

public class karakter : MonoBehaviour {

    

    Rigidbody2D myrigidbody;
    Animator myanimator;
    float horizontal;
    float movementspeed =0.1f;
    float jumpforce = 700f;
    bool yerdemi;
    public bool flipside;


	void Start () {


        myrigidbody = GetComponent<Rigidbody2D>();
        myanimator = GetComponent<Animator>();

	}
	
	
	void FixedUpdate ()
    {
        movement();
        ziplama();
        flip();

    }


    void movement()
    {
        horizontal = Input.GetAxis("Horizontal");
        transform.Translate(new Vector2(horizontal * movementspeed, 0));
        myanimator.SetFloat("speed", Mathf.Abs(horizontal));
        
    }

    void OnTriggerEnter2D()
    {
        myanimator.SetBool("groundcheck", true);
        yerdemi = true;
    }

    void OnTriggerStay2D()
    {
        myanimator.SetBool("groundcheck", true);
        yerdemi = true;

    }

    void OnTriggerExit2D()
    {
        myanimator.SetBool("groundcheck", false); 
        yerdemi = false;
    }

    void ziplama()
    {
        myanimator.SetFloat("vertical", myrigidbody.velocity.y);
        if (Input.GetButtonDown("Jump")&& yerdemi == true)
        {
             myrigidbody.AddForce(new Vector2(0, jumpforce));
        }
    }
    
    void flip()
    {
        if(horizontal>0)
        {
            transform.localScale = new Vector2(2,2);
            flipside = false;
        }
        if(horizontal<0)
        {
            transform.localScale = new Vector2(-2, 2);
            flipside = true;
        }
    }


}
